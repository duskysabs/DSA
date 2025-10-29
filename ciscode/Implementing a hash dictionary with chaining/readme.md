mplement a Hash Dictionary with Chaining
By Justine Carl Lequigan

DSA
Categories:

None
You are tasked with implementing a dictionary data structure using hashing with separate chaining. The dictionary should store integers in linked lists within a fixed-size array (buckets).

Each element is placed into a bucket based on the ones digit of the number (e.g., 23 goes into bucket 3). Within each bucket, elements must be stored in ascending order and without duplicates.

You must implement the following operations:

- Initialize Dictionary
   - Set all buckets to NULL.

- Hash Function
   - Return the bucket index based on the ones digit of the number.

- Insert (Unique & Sorted)
   - Insert an element into the correct bucket.
   - Maintain ascending order.

   - Do not allow duplicates.

- Delete Element
   - Remove an element from the dictionary if it exists.
   - Print a message whether deletion was successful or not.

- Membership Check
   - Return TRUE if the element exists in the dictionary, else FALSE.

- Display Dictionary
   - Print the contents of each bucket in ascending order.
   - Print "EMPTY" for empty buckets.
 
- Make Null
   - Delete all elements in the dictionary.
   - Reset all buckets to NULL.