import chardet

def detect_encoding(file_path):
    with open(file_path, "rb") as file:
        raw_data = file.read()
        result = chardet.detect(raw_data)
        encoding = result["encoding"]


def read_file_with_detected_encoding(file_path):
    encoding = detect_encoding(file_path)
    with open(file_path, "r", encoding=encoding) as file:
        content = file.read()
    return content


# Example usage:
file_path = "requirements.txt"  # Replace with your file path
encoding = detect_encoding(file_path)
print(f"Detected encoding: {encoding}")

content = read_file_with_detected_encoding(file_path)
print("File content:")
print(content)
