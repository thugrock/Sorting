import sys 
A = [64, 27, 12, 22, 11] 
  
# Traverse through all array elements 
for i in range(len(A)): 
      
    # Find the minimum element in remaining  
    # unsorted array 
    min_idx = i 
    for j in range(i+1, len(A)): 
        if A[min_idx] > A[j]: 
            min_idx = j 
              
    A[i], A[min_idx] = A[min_idx], A[i] 
  
print ("Sorted array") 
for i in range(len(A)): 
    print("%d" %A[i]), 