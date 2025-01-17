%% CENG371 - HW4 supplementary file
%% mferhata @ 03/01/24

funcs   = [ "mult_row_uniform", "mult_row_nonuni", ...
            "mult_proj_Gauss", "mult_proj_Gauss_orth"];
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% A * B

load A.mat
load B.mat
I       = [1:10:size(A,2)/2 size(A,2):20:size(A,2) size(A,2)];
[tA,~]  = run(A, B, @mult_naive, funcs, I, 1); % mult_naive is your implementation
plotter ("Runtimes for $A\times B$", tA, funcs, I, 'se'); saveas (1, 'runtimes_AB.png'); close all;
I       = [1:10:size(A,2)/2 size(A,2):20:size(A,2) size(A,2)];
[~,reA] = run(A, B, @mtimes, funcs, I, 100); % mtimes is a built-in MATLAB function. check: >> help mtimes
plotter ("Relative errors for $A\times B$ averaged over 100 runs", reA(:,1:end-2), funcs, I(1:end-2), 'ne'); saveas (1, 'res_AB_dropped.png'); close all;
plotter ("Relative errors for $A\times B$ averaged over 100 runs", reA, funcs, I, 'sw'); saveas (1, 'res_AB.png'); close all;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% C * C'

load C.mat
I       = [1:50:size(C,2)/2 size(C,2)/2:100:size(C,2) size(C,2)];
[tC,~]  = run(C, C', @mult_naive, funcs, I, 1);
plotter ("Runtimes for $C\times C^T$", tC, funcs, I, 'se'); saveas (1, 'runtimes_C.png'); close all;
I       = [1:50:size(C,2)/2 size(C,2)/2:100:size(C,2) size(C,2)];
[~,reC] = run(C, C', @mtimes, funcs, I, 50);
plotter ("Relative errors for $C\times C^T$ averaged over 50 runs", reC(:,1:end-2), funcs, I(1:end-2), 'ne'); saveas (1, 'res_C_dropped.png'); close all;
plotter ("Relative errors for $C\times C^T$ averaged over 50 runs", reC, funcs, I, 'sw'); saveas (1, 'res_C.png'); close all;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Helpers -- if any of them causes a problem (due to conflicting MATLAB versions) feel free to modify them
% the functionalities of each function should be clear

% computes A*B where @mult gives the groundtruth result
% funcs denotes the randomized implementations to be tested
% I: array of c's (as referred in the Algorithms in Mahoney's lecture notes)
% cnt: number of repetitions to get average relative errors.
function [times,res] = run (A, B, mult, funcs, I, cnt)
    times   = [];
    res     = [];
    tic; 
    gt = mult(A,B); 
    gt_time = toc;
    for funcname=funcs
        func    = str2func(funcname);
        T       = [];
        E       = [];
        for k=I
            t   = 0;
            re  = 0;
            for i=1:cnt
                tic; 
                D   = func(A, B, k, mult);
                t   = t  + toc;
                re  = re + rel_err(D, gt);
            end
            T   = [T, t/cnt];
            E   = [E, rel_err(D,gt)/cnt];
        end
        times   = [times;   T];
        res     = [res;     E];
        fprintf ('Completed MM-run for %s\n', funcname);
    end
    gt_time = gt_time * ones(size(I));
    times   = [times; gt_time];
end

% relative l2 error between A and B
function ret = rel_err (A, B)
    ret = norm(A-B) / norm(B);
end

% helper for decent looking plots
function plotter (mytitle, myarray, names, I, loc)
    figure (1);
    semilogy (I, myarray', 'linewidth', 2);
    axis tight;
    grid on;
    legend (    arrayfun(@(x) ['$\verb|' char(x) '|$'], ...
                            names, 'Uni',false),        ...
                'Interpreter', 'latex', 'FontSize', 14, ...
                'Location', loc     );
    title (mytitle, 'Interpreter', 'latex', 'FontSize', 16);
    set (gcf, 'color', 'w', 'Position', [0 0 1000 600]);
end
