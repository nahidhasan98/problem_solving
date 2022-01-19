def getPoints(ppoints, need):
    res = []

    for p1 in ppoints:
        slopes = {}
        slopePoints = {}

        undefined = 0
        undefinedPoints = []

        for p2 in ppoints:
            if p1 != p2:
                up = p1[1]-p2[1]
                down = p1[0]-p2[0]

                if down == 0:
                    undefined += 1
                    undefinedPoints.append(p2)
                else:
                    currSlope = up / down

                    if currSlope not in slopes:
                        slopes[currSlope] = 0
                    slopes[currSlope] += 1

                    if currSlope not in slopePoints:
                        slopePoints[currSlope] = []
                    slopePoints[currSlope].append(p2)

        if undefined+1 == need:
            res.append(p1)
            for p in undefinedPoints:
                res.append(p)
            return res
        else:
            for key in slopes:
                if slopes[key]+1 == need:
                    res.append(p1)
                    for p in slopePoints[key]:
                        res.append(p)
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