"""
This module provides functions to hash files in a folder and persist the hashes in a file. 
"""


# import the libraries needed for hashing and general os functionality
import hashlib
import os

"""
create a function 'hash_files' that recursively iterates over all files in a folder and subfolders and hashes the files.
Arguments: 
- foler_path: the path to the folder to hash
Returns: - a dictionary with the file path as key and the hash as value
"""