from cryptography.hazmat.primitives.asymmetric import rsa
from cryptography.hazmat.primitives import serialization

# Generate RSA key pair
private_key = rsa.generate_private_key(
    public_exponent=65537,
    key_size=2048
)

# Serialize the private key to PEM format
private_pem = private_key.private_bytes(
    encoding=serialization.Encoding.PEM,
    format=serialization.PrivateFormat.TraditionalOpenSSL,
    encryption_algorithm=serialization.NoEncryption()
)

# Serialize the public key to PEM format
public_pem = private_key.public_key().public_bytes(
    encoding=serialization.Encoding.PEM,
    format=serialization.PublicFormat.SubjectPublicKeyInfo
)

# Save the private key to a file
with open('private_key.pem', 'wb') as private_file:
    private_file.write(private_pem)

# Save the public key to a file
with open('public_key.pem', 'wb') as public_file:
    public_file.write(public_pem)

print("Private Key:")
print(private_pem.decode())

print("\nPublic Key:")
print(public_pem.decode())
