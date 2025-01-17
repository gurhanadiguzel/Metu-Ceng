#ifndef __HW1__PARSER__
#define __HW1__PARSER__

#include <cmath>
#include <string>
#include <vector>

namespace parser {
// Notice that all the structures are as simple as possible
// so that you are not enforced to adopt any style or design.
struct Vec3f {
    double x, y, z;

    Vec3f& operator=(const Vec3f& vector) {
        x = vector.x;
        y = vector.y;
        z = vector.z;
        return *this;
    }

    bool operator==(const Vec3f& vector) {
        if (x == vector.x && y == vector.y && z == vector.z)
            return true;
        return false;
    }

    double length() const {
        double result = powf(x, 2) + powf(y, 2) + powf(z, 2);
        return sqrt(result);
    }

    Vec3f normalize() {
        Vec3f normalized;
        double length = this->length();
        if (length != 0.0f) {
            normalized.x = x / length;
            normalized.y = y / length;
            normalized.z = z / length;
        }
        return normalized;
    }
};

struct Vec3i {
    int x, y, z;
};

struct Vec4f {
    double x, y, z, w;
};

struct Camera {
    Vec3f position;
    Vec3f gaze;
    Vec3f up;
    Vec4f near_plane;
    double near_distance;
    int image_width, image_height;
    std::string image_name;
};

struct PointLight {
    Vec3f position;
    Vec3f intensity;
};

struct Material {
    bool is_mirror;
    Vec3f ambient;
    Vec3f diffuse;
    Vec3f specular;
    Vec3f mirror;
    double phong_exponent;
};

struct Face {
    int v0_id;
    int v1_id;
    int v2_id;
};

struct Mesh {
    int material_id;
    std::vector<Face> faces;
};

struct Triangle {
    int material_id;
    Face indices;
};

struct Sphere {
    int material_id;
    int center_vertex_id;
    double radius;
};

struct Scene {
    // Data
    Vec3i background_color;
    double shadow_ray_epsilon;
    int max_recursion_depth;
    std::vector<Camera> cameras;
    Vec3f ambient_light;
    std::vector<PointLight> point_lights;
    std::vector<Material> materials;
    std::vector<Vec3f> vertex_data;
    std::vector<Mesh> meshes;
    std::vector<Triangle> triangles;
    std::vector<Sphere> spheres;

    // Functions
    void loadFromXml(const std::string& filepath);
};
}  // namespace parser

#endif
