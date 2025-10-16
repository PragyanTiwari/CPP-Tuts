

# Circular Queue


queue (insert) : to add element to the arr
    - first check if the arr is not full.
    - move front from -1 to 0, if front has not participated.
    - incremement the rear index.
    - store the element on index rear in the array.


queue (delete): to delete element from the arr
    - first check if the arr is not empty.
    - take the element sitting on the front & store it in a variable
    - tell them this is the element to be deleted
    - move the front index
        - if front & rear are equal : reset it i.e. front & rear equals to -1.
        - else increment the front circularly. 