import re

def format_diff(diff_content):
    formatted_diff = []

    diff_lines = diff_content.splitlines()
    left = right = 0
    ll = rl = 0

    for line in diff_lines:
        match = re.match(r'^@@ -([0-9]+),([0-9]+) [+]([0-9]+),([0-9]+) @@', line)
        if match:
            left = int(match.group(1))
            ll = len(match.group(2))
            right = int(match.group(3))
            rl = len(match.group(4))
            formatted_diff.append(line)
            continue
        
        if re.match(r'^(---|\+\+\+|[^-+ ])', line):
            formatted_diff.append(line)
            continue

        line_content = line[1:]

        if line.startswith('-'):
            padding = ' ' * rl
            formatted_diff.append(f"-{left:<{ll}} {padding}:{line_content}")
            left += 1
        elif line.startswith('+'):
            padding = ' ' * ll
            formatted_diff.append(f"+{padding} {right:<{rl}}:{line_content}")
            right += 1
        else:
            formatted_diff.append(f" {left:<{ll}} {right:<{rl}}:{line_content}")
            left += 1
            right += 1

    return "\n".join(formatted_diff)

# stolen from Gotham City
def find_line_numbers(diff_string, word):
    # Escape the word to avoid issues with special characters
    escaped_word = re.escape(word)
    
    # Regular expression to find the line number before the given word
    pattern = re.compile(r'(\d+):.*\b' + escaped_word + r'\b')

    # Find all matches
    matches = pattern.findall(diff_string)

    return matches


if __name__ == "__main__":
    diff_content = open("plain_diff_2.txt").read()
    # bytes_content = str(bytes(diff_content,"UTF-8"))
    print()
    normal_string = diff_content.encode().decode('unicode_escape')
    # bytes_content = bytes_content.decode("UTF-8")
    # raw_string_repr = repr(diff_content)[1:-1]
    # print(raw_string_repr)
    print("******----------******------------*******------------")
    print("******----------******------------*******------------")
    formatted_diff = format_diff(normal_string)
    print(formatted_diff)