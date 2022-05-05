while True:
    highest = highest_i = -1

    for i in range(8):
        mountain_h = int(input())

        if mountain_h > highest:
            highest = mountain_h
            highest_i = i

    print(highest_i)