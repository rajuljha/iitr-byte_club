# import re

# def find_line_numbers(diff_string, word):
#     # Escape the word to avoid issues with special characters
#     escaped_word = re.escape(word)
    
#     # Regular expression to find the line number before the given word
#     pattern = re.compile(r'(\d+):.*\b' + escaped_word + r'\b')

#     # Find all matches
#     matches = pattern.findall(diff_string)

#     return matches


# diff_string = open('tmp.txt').read()

# # Example usage
# word_to_search = "remove_diff_regex"
# line_numbers = find_line_numbers(diff_string, word_to_search)
import chardet

def detect_encoding(file_path):
    with open(file_path, 'rb') as file:
        raw_data = file.read()
        result = chardet.detect(raw_data)
        encoding = result['encoding']
        return encoding

def read_file_with_detected_encoding(file_path):
    encoding = detect_encoding(file_path)
    with open(file_path, 'r', encoding=encoding) as file:
        content = file.read()
    return content

# Example usage:
file_path = 'requirements.txt'  # Replace with your file path
encoding = detect_encoding(file_path)
print(f"Detected encoding: {encoding}")

content = read_file_with_detected_encoding(file_path)
print("File content:")
print(content)