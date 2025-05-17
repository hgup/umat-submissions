import streamlit as st
import subprocess

def run_c_program(word):
    try:
        result = subprocess.check_output(["./a.out", word], stderr=subprocess.STDOUT, text=True)
        return result.strip()
    except subprocess.CalledProcessError as e:
        return f"Error executing C program: {e.output}"

def main():
    st.title("Spell Check++ Web App")
    user_word = st.text_input("Enter a word to check or correct:", key="user_input")
    if st.button("Check") or st.session_state.user_input:
        result = run_c_program(user_word)
        st.write(f"Result: {result}")

if __name__ == "__main__":
    main()
