def binarySearch(row,elem):
    i= 0
    j = len(row) -1

    while i <= j:
        mid = (i+j) // 2
        if row[mid] == elem:
            return True
        elif elem > row[mid]:
            i =mid + 1
        else:
            j = mid -1
    return False
def searchMatrix(matrix,elem):
 
    for row in matrix:

            if binarySearch(row,elem):
                return True

    return False


def searchMatrix_optimized(matrix, elem):
    row_length = len(matrix)
    col_length =  len(matrix[0])
    i = 0
    j = col_length-1

    while i < row_length and j>=0:
        if matrix[i][j] == elem:
            return True
        elif matrix[i][j] > elem:
            j-=1
        else:
            i+=1
    return False



matrix = [[10,15,35,60],
          [20,45,55,65],
          [30,50,60,70],
          [40,57,76,80]]
print(searchMatrix(matrix,50))
print(searchMatrix_optimized(matrix,10))