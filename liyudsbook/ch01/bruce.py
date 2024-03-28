import os.path

output_path = os.path.join(os.path.dirname(__file__), "out.txt")


with open(output_path, "w+") as f:
    for p in range(1, 10**18):
        for a in range(1, 10**18):
            for b in range(1, 10**18):
                cur_line = (
                    str(a)
                    + "\t"
                    + str(b)
                    + "\t"
                    + str(p)
                    + "\t"
                    + str(a * b % p)
                    + "\n"
                )
                f.write(cur_line)
