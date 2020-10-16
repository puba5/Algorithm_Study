def solution(h, w, n, board):

    answer = 0
    di = [0, 1, 1] # garo , sero, daegak
    dj = [1, 0, 1]

    test = [0, 0, 0]
    for i in range(h):
        for j in range(w):
            if int(board[i][j]) < 1:
                continue
            #print(str(i) + " ," + str(j))
            for d in range(int(board[i][j]) - 1, 3):
                print(str(i) + ", " + str(j) + " - " + board[i][j])
                mok = 1
                plus_i = i
                plus_j = j
                for k in range(n + 1):

                    plus_i = plus_i + di[d]
                    plus_j = plus_j + dj[d]
                    if plus_i < h and plus_j < w:
                        if int(board[plus_i][plus_j]) > 0:
                            mok = mok + 1
                            board[i] = board[i][0:j] + str(d + 2) + board[i][j+1:w]

                        else:
                            break

                if mok == n:
                    print(str(i) + ", " + str(j) + " (" + str(d) + ")")
                    answer = answer + 1
                    test[d] = test[d] + 1
    print(str(test[0]) + ", " + str(test[1]) + ", " + str(test[2]))
    return answer

h = 7
w = 9
n = 4
board = ["111100000","000010011","111100011","111110011","111100011","111100010","111100000"]
print(solution(h, w, n, board))

