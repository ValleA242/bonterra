"""
This module provides function to hash files in a folder and persist the hashes in a file.
"""

# Import the libraries needed for hashing and general os functions
import hashlib
import os

"""
Create a function 'recurse_hash_files' that recursively iterates over all files in a folder and subfolders.
Arguments:
- folder_path: the path to the folder to hash
Returns:
- a dictionary with the file path as key and the hash as value
"""
def recurse_hash_files(folder_path):
    # Create an empty dictionary to store the hashes
    hashes = {}
    # Iterate over all files in the folder
    for root, dirs, files in os.walk(folder_path):
        for file in files:
            # Create the full path to the file
            file_path = os.path.join(root, file)
            # Open the file in binary read mode
            with open(file_path, 'rb') as f:
                # Read the content of the file
                content = f.read()
                # Calculate the hash of the content
                hash_value = hashlib.sha256(content).hexdigest()
                # Store the hash in the dictionary with the file path as key
                hashes[file_path] = hash_value
    # Return the dictionary with the hashes
    return hashes

"""
Create a test function 'test_recurse_hash_files' to test the 'recurse_hash_files' function.
Details:
- The test function should create a test folder with a test file, call the 'recurse_hash_files' function,
"""
def test_recurse_hash_files():
    # Define a test folder path
    test_folder = 'test_folder'
    # Create a test file in the folder
    with open(os.path.join(test_folder, 'test_file.txt'), 'w') as f:
        f.write('This is a test file.')
    # Call the 'recurse_hash_files' function
    hashes = recurse_hash_files(test_folder)
    # Check if the hash is correct
    assert hashes[os.path.join(test_folder, 'test_file.txt')] == 'd1f7b2d7d3b3f3f3c'
    # Print a success message
    print('Test passed successfully!')

"""
write a function to call the test function
"""
def main():
    test_recurse_hash_files()

# Call the main function
if __name__ == '__main__':
    main()


