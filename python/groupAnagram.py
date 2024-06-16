def groupAnagram(list1):
    group_anagram = {}
    for word in list1:

        word1 = "".join(sorted(word))
        if word1 in group_anagram:
            group_anagram[word1].append(word)
        else:
            group_anagram[word1] = [word]
    final_list = []
    for key in group_anagram:
        final_list.append(group_anagram[key])
    return final_list




print(groupAnagram(["eat","tea","tan","ate","nat","bat"]))
print(groupAnagram(["a"]))
print(groupAnagram([""]))