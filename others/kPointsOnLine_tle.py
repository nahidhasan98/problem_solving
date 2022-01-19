def sameLine( p1, p2, p3 ):
    left  = ( p1[0] - p2[0] ) * ( p2[1] - p3[1] )
    right = ( p2[0] - p3[0] ) * ( p1[1] - p2[1] )

    if ( left == right ):
        return True
    return False

def getPoints(ppoints, need):
    res = []

    for i in range(len(ppoints)):
        for j in range(i+1, len(ppoints)):
            res = []
            counter = 0

            for k in range(len(ppoints)):
                if sameLine(ppoints[i],ppoints[j],ppoints[k]):
                    counter += 1
                    res.append(ppoints[k])
            
            if counter == need:
                return res

    return res

n, k = input().split()
n, k = [int(n), int(k)]

points = []

for i in range(n):
    x, y = input().split()
    x, y = [int(x), int(y)]
    points.append([x,y])

v = getPoints(points, k)
for p in v:
    print(p[0], p[1])