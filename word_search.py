''' This program goes over a 2d array to find a word return true if it finds the word or else it return false '''

class Solution(object):
    def dfs(self,board,i,j,count,word):
      if len(word) == count:
        return True
    
      if i < 0 or j < 0 or i >= len(board) or j >= len(board[i])or board[i][j] != word[count]:
        return False

      temp_val = board[i][j]
      board[i][j] = ' '
      result =  dfs(board,i+1,j,count+1,word) or dfs(board,i-1,j,count+1,word) or dfs(board,i,j+1,count+1,word) or dfs(board,i,j-1,count+1,word)
      board[i][j] = temp_val
      return result
    
    
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        
        for i,item  in enumerate(board):
            for j,elem in enumerate(item):
              if board[i][j]==word[0] and dfs(board, i ,j,0,word):
                return True
        return False
        