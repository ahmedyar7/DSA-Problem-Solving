import os
import json
import sys
import time


def scan_directory(directory):
    """
    Scan a directory recursively and collect file information

    Args:
        directory (str): Path to the directory to scan

    Returns:
        list: List of dictionaries containing file information
    """
    files = []
    try:
        for root, _, filenames in os.walk(directory):
            for filename in filenames:
                filepath = os.path.join(root, filename)
                try:
                    # Collect file metadata
                    file_stat = os.stat(filepath)
                    files.append(
                        {
                            "filename": filename,
                            "path": filepath,
                            "size": file_stat.st_size,
                            "modified_time": file_stat.st_mtime,
                        }
                    )
                except Exception as file_error:
                    print(f"Error processing {filepath}: {file_error}")
    except Exception as walk_error:
        print(f"Error walking directory {directory}: {walk_error}")

    return files


def save_scan_to_json(files, output_file):
    """
    Save scan results to a JSON file

    Args:
        files (list): List of file dictionaries
        output_file (str): Path to output JSON file
    """
    try:
        with open(output_file, "w") as f:
            json.dump(files, f, indent=2)
        print(f"Scan results saved to {output_file}")
    except Exception as e:
        print(f"Error saving scan results: {e}")


def compare_scans(cpp_scan_file, python_scan_result):
    """
    Compare file scans between C++ and Python implementations

    Args:
        cpp_scan_file (str): Path to C++ scan JSON file
        python_scan_result (list): Python scan results
    """
    try:
        with open(cpp_scan_file, "r") as f:
            cpp_scan = json.load(f)

        # Detailed comparison
        print("\n--- SCAN COMPARISON ---")
        print(f"CPP Scan Total Files: {len(cpp_scan)}")
        print(f"Python Scan Total Files: {len(python_scan_result)}")

        # Calculate total sizes
        cpp_total_size = sum(file["size"] for file in cpp_scan)
        py_total_size = sum(file["size"] for file in python_scan_result)

        print(f"CPP Total File Size: {cpp_total_size / (1024 * 1024):.2f} MB")
        print(f"Python Total File Size: {py_total_size / (1024 * 1024):.2f} MB")

        # Find discrepancies
        cpp_paths = {file["path"] for file in cpp_scan}
        py_paths = {file["path"] for file in python_scan_result}

        missing_in_cpp = py_paths - cpp_paths
        missing_in_py = cpp_paths - py_paths

        print("\nFiles missing in CPP scan:")
        for path in list(missing_in_cpp)[
            :10
        ]:  # Limit to 10 to prevent overwhelming output
            print(path)

        print("\nFiles missing in Python scan:")
        for path in list(missing_in_py)[
            :10
        ]:  # Limit to 10 to prevent overwhelming output
            print(path)

    except Exception as e:
        print(f"Error comparing scans: {e}")


def main():
    """
    Main driver function for file scan comparison
    """
    # Directories to scan (customize as needed)
    scan_directories = [
        "C:/Users",  # Example directory, modify as per your system
        "C:/Program Files",
        "C:/Windows",
    ]

    # Output files
    cpp_scan_output = "cpp_file_scan.json"
    python_scan_output = "python_file_scan.json"

    # Measure scanning time
    start_time = time.time()

    # Perform scans
    all_files = []
    for directory in scan_directories:
        try:
            print(f"Scanning directory: {directory}")
            directory_files = scan_directory(directory)
            all_files.extend(directory_files)
        except Exception as e:
            print(f"Error scanning {directory}: {e}")

    # Save Python scan results
    save_scan_to_json(all_files, python_scan_output)

    # Performance metrics
    end_time = time.time()
    print(f"\nTotal Scan Time: {end_time - start_time:.2f} seconds")
    print(f"Total Files Scanned: {len(all_files)}")

    # Compare with C++ scan results (assuming cpp_file_scan.json exists)
    if os.path.exists(cpp_scan_output):
        compare_scans(cpp_scan_output, all_files)
    else:
        print(f"C++ scan file {cpp_scan_output} not found. Skipping comparison.")


if __name__ == "__main__":
    main()
