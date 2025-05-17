**Usage Instructions**

This repository contains three files: srep, repl_l, and repl_c, each designed to perform specific text manipulation tasks akin to commonly used Linux commands.

**How to Use:**

```bash
#Go to the Directory
#where you can find install.sh
#Open terminal and run these commands

chmod u+x install.sh &&  ./install.sh
```



## `srep`

```bash
bash Usage: srep pattern [options] [file ....] 
```

`srep` is a versatile script that mimics the functionality of the `grep ` command in Linux. It searches for a specified `pattern` in one or more `file`s and outputs lines or highlights the words containing the `pattern`.

Options:

- `-i` : Ignore case distinctions.
- `-w `: Match whole words only.
- `-c` : Display count of matching lines.
- `-n `: Display line numbers along with matching lines.



## `repl_l`
```bash
bash Usage: repl_l linenumber "string" file
```

`repl_l` is a script designed to replace a line in a specified `file` at a given `linenumber` with the provided `"string"`.



## `repl_c`
```bash
Usage: repl_c file "string1" "string2"
```



`repl_c` allows users to replace occurrences of `"string1"` with `"string2"` in the specified file.



**Example Usage:**

- To search for the pattern "example" in a file named `sample.txt ` ignoring case distinctions and displaying line numbers:

  ```bash
  srep -i -n "example" sample.txt
  ```

- To replace line number 5 in `file.txt` with the string “Hello World”:

  ```bash
  repl_l 5 "Hello World" file.txt
  ```

- To replace occurrences of "old" with "new" in `data.txt`:

  ```bash
  repl_c data.txt "old" "new"
  ```

Please ensure you have appropriate permissions to execute these scripts and provide valid inputs as specified in the usage instructions.

For more details on each command's usage and options, refer to the respective script files.

**Note:**
These scripts are designed for basic text manipulation tasks and may not encompass the full functionality of their counterparts in the Linux environment. Feel free to modify and extend them according to your requirements.

**Author:**

*Name - **Siba charan Das***

*Regd. No - **211214***

*III B.Sc (Hons.)(Mathematics)*

***UCSC-606 : Mini Project***