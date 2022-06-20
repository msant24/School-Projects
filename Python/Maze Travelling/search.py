from collections import deque
from queue import PriorityQueue
import argparse
import copy

#Converts the text mazes into 2D matrices
def txtToMatrix(file):
    matrix = []
    with open(file) as myfile:
        for line in myfile:
            lineStr = ""
            line = line.strip()
            for tok in line:
                lineStr += tok
            matrix.append(lineStr)
        return matrix


#prints maze in command line
def printMaze(mat):
    for i in mat:
        print(i)

#find start state
def findStart(mat):
    row = 0
    for i in mat:
        col = 0
        row += 1
        for j in i:
            col += 1
            if (j == 'B'):
                return row - 1, col - 1
            else:
                continue
    print("Cannot find start state")

#find goal state
def findGoal(mat):
    row = 0
    for i in mat:
        col = 0
        row += 1
        for j in i:
            col += 1
            if (j == 'F'):
                return (row - 1, col - 1)
            else:
                continue
    print("Cannot find goal state")

#function for safe transitions
def safeTransitions(mat, row, col, visited):
    return ((mat[row][col] != '%') and (
                (row, col) not in visited))


def findPathDFS(maze): 
    if maze == []:
        return maze
    strt = findStart(maze)
    final = DFS(strt[0], strt[1], maze)  # Go to DFS.
    return final

def findPathBFS(maze):
    if maze == []:
        return maze
    strt = findStart(maze)
    final = BFS(strt[0], strt[1], maze)  # Go to BFS.
    return final

def findPathUniform(maze):
    if maze == []:
        return maze
    strt = findStart(maze)
    final = Uniform(strt[0], strt[1], maze)  # Go to Uniform.
    return final


def findPathAstar(maze):
    if maze == []:
        return maze
    strt = findStart(maze)
    final = Astar(strt[0], strt[1], maze)
    return final

def DFS(x, y, maze):
    visited = set()
    stack = []
    stack.append([(x, y)])

    while (len(stack) != 0):
        current_list = stack[-1]
        current_state = current_list[-1]
        stack = stack[:len(stack) - 1]
        row = current_state[0]
        col = current_state[1]
        visited.add(current_state)
        if (maze[row][col] == "F"):
            print("Found goal", row, col)
            return current_list
        possible_actions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        for coord in possible_actions:
            dx = coord[0]
            dy = coord[1]
            if (safeTransitions(maze, row + dx, col + dy, visited)):
                temp_list = current_list.copy()
                temp_list.append((row + dx, col + dy))
                stack.insert(0, temp_list)

def BFS(x, y, maze):
    q = deque()
    visited = set()
    q.append([(x, y)])
    while(len(q) != 0):
        current_list = q[0]
        current_state = current_list[-1]
        q.popleft()
        row = current_state[0]
        col = current_state[1]
        visited.add(current_state)
        if (maze[row][col] == "F"):
            print("Found goal", row, col)
            return current_list
        possible_actions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        for coord in possible_actions:
            dx = coord[0]
            dy = coord[1]
            if (safeTransitions(maze, row + dx, col + dy, visited)):
                temp_list = current_list.copy()
                temp_list.append((row + dx, col + dy))
                q.insert(0, temp_list)



def ManhatDist(x1, y1, goal):
    return (abs(x1 - goal[0]) + abs(y1-goal[1]))

def Uniform(x, y, maze):
    visited = set()
    goal = findGoal(maze)
    pq = [] 
    heuristic = ManhatDist(x, y, goal)
    pq.append(([(x,y)], heuristic))
    while(len(pq) != 0):
        current_list = pq[0][0]
        current_state = current_list[-1]
        pq.pop(0)
        row = current_state[0]
        col = current_state[1]
        visited.add(current_state)
        if (maze[row][col] == "F"):
            print("Found Goal", row, col)
            return current_list
        possible_actions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        for coord in possible_actions:
            dx = coord[0]
            dy = coord[1]
            if (safeTransitions(maze, row + dx, col + dy, visited)):
                temp_list = current_list.copy()
                temp_list.append((row + dx, col + dy))
                temp_tup = (temp_list, ManhatDist(row+dx, col+dy, goal))
                pq.append(temp_tup)
                pq  = sorted(pq, key=lambda x: x[1])

def Astar(x, y, maze):
    visited = set()
    goal = findGoal(maze)
    pq = [] 
    heuristic = ManhatDist(x, y, goal)
    counter = 1
    func = counter + heuristic
    pq.append(([(x,y)], func))
    while(len(pq) != 0):
        current_list = pq[0][0]
        current_state = current_list[-1]
        pq.pop(0)
        row = current_state[0]
        col = current_state[1]
        visited.add(current_state)
        if (maze[row][col] == "F"):
            print("Found goal", row, col)
            return current_list
        possible_actions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        counter += 1
        for coord in possible_actions:
            dx = coord[0]
            dy = coord[1]
            if (safeTransitions(maze, row + dx, col + dy, visited)):
                temp_list = current_list.copy()
                temp_list.append((row + dx, col + dy))
                heur = ManhatDist(row+dx, col+dy, goal)
                new_func = counter + heur
                temp_tup = (temp_list, new_func)
                pq.append(temp_tup)
                pq  = sorted(pq, key=lambda x: x[1])

def update_maze(maze, path):
    stringLis = []

    for row in maze:
        stringLis.append(list(row))
    for coord in path:
        stringLis[coord[0]][coord[1]] = "0"
    updated = []
    for i in stringLis:
        updated.append("".join(i))
    return updated

def print_maze(maze):
    for row in maze:
        print(row)

def main():
    argScan = argparse.ArgumentParser()
    argScan.add_argument("-method", required=True, help="mazeMethIn")
    argScan.add_argument("mazeNameIn")
    args = argScan.parse_args()
    Method = args.method
    print(Method)
    mazeName = args.mazeNameIn
    print(mazeName)
    maze = txtToMatrix(mazeName)

    if(Method == 'Depth'):
        path0 = findPathDFS(maze)
        maze0 = update_maze(maze, path0)
        print_maze(maze0)
    elif(Method == 'Breadth'):
        path4 = findPathBFS(maze)
        maze1 = update_maze(maze, path4)
        print_maze(maze1)
    elif(Method == 'Uniform'):
        path2 = findPathUniform(maze)
        maze2 = update_maze(maze, path2)
        print_maze(maze2)
    elif(Method == 'Astar'):
        path5 = findPathAstar(maze)
        maze3 = update_maze(maze, path5)
        print_maze(maze3)


main()

#Sources: https://www.geeksforgeeks.org/search-algorithms-in-ai/ https://github.com/raulorteg/ai-maze-python