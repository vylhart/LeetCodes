# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if root==None:
            return []
        p = [root]
        q = []
        ans = []
        while len(p)>0:
            ans.append([])
            q = []
            for i in p:
                ans[-1].append(i.val)
                if i.left:
                    q.append(i.left)
                if i.right:
                    q.append(i.right)
            q.reverse()
            p = []
            ans.append([])
            for i in q:
                ans[-1].append(i.val)
                if i.right:
                    p.append(i.right)
                if i.left:
                    p.append(i.left)
            p.reverse()

            
        if(len(ans)>0 and len(ans[-1])==0):
            ans.pop()
        return ans