#!/bin/bash

# Compile the program
make

# Move the executable to /usr/local/bin/
sudo mv repl_l /usr/local/bin/

# Add /usr/local/bin to the PATH if not already present
if [[ ":$PATH:" != *":/usr/local/bin:"* ]]; then
    echo 'export PATH="/usr/local/bin:$PATH"' >> ~/.bashrc
    source ~/.bashrc
fi
