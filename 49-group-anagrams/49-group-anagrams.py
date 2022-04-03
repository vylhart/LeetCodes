class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        dic = {}
        for s in strs:
            f = [0]*26
            #print(f)
            for i in list(s):
                f[ord(i)-ord('a')] += 1
            #print(f)
            key = '.'.join([str(i) for i in f])
            #print(key)
            if key in dic:
                dic[key].append(s)
            else:
                dic[key] = [s]
            #print(dic)
        ans = []
        for key in dic:
            ans.append(dic[key])
        return ans
        