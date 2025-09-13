N = int(input())

pattern = ["@   @", "@   @", "@@@@@", "@   @", "@@@@@"]

if N == 1:
    for line in pattern:
        print(line)
else:
    for row_pattern in pattern:
        for _ in range(N):
            output_line = ""
            for char in row_pattern:
                output_line += char * N
            print(output_line)
