# c_wrapper.py

import subprocess

def run_c_program(word):
    try:
        # Execute the C program and capture its output
        result = subprocess.check_output(["./a.out", word], stderr=subprocess.STDOUT, text=True)
        return result.strip()  # Assuming the output is a single line
    except subprocess.CalledProcessError as e:
        return f"Error executing C program: {e.output}"

# Example usage:
if __name__ == "__main__":
    user_word = input("Enter a word: ")
    print(run_c_program(user_word))
