def longestNon(inputStr):
    i = 0
    j = 0
    seen=set()
    max_tillnow = 0
    while j < len(inputStr):
        if inputStr[j] not in seen:
            seen.add(inputStr[j])
            j+=1
            max_tillnow = max(len(seen),max_tillnow)
        else:
            seen.remove(inputStr[i])
            i+=1
    return max_tillnow
inputStr = "abcdc"
print(longestNon(inputStr))