import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py database.csv sequence.txt")
        return
    
    database_filename = sys.argv[1]
    sequence_filename = sys.argv[2]

    # TODO: Read database file into a variable
    with open(database_filename, "r", newline="") as db_file:
        reader = csv.DictReader(db_file)
        # STR list comes from header (all except name)
        str_list = reader.fieldnames[1:]
        
        # Store each person as a dict: {"name}: ..., "AGATC": 4, ...}
        people = []
        for row in reader:
            person = {"name": row["name"]}
            for s in str_list:
                person[s] = int(row[s])
            people.append(person)
            
    # TODO: Read DNA sequence file into a variable
    with open(sequence_filename, "r") as seq_file:
        sequence = seq_file.read().strip()
        
    # TODO: Find longest match of each STR in DNA sequence
    found_counts = {}
    for s in str_list:
        found_counts[s] = longest_match(sequence, s)
    
    # TODO: Check database for matching profiles
    for person in people:
        match = True
        for s in str_list:
            if person[s] != found_counts[s]:
                match = False
                break
        
        if match:
            print(person["name"])
            return
        
    print("No match")
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1
            
            # If there is no match in the substring
            else:
                break
        
        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in sequence, return longest run found
    return longest_run


main()
