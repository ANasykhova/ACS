import sys
import time

from container import Container


# Error message.
def err_message1():
    print("incorrect command line!\n"
          "  Waited:\n"
          "     command -f infile outfile01 outfile02\n"
          "  Or:\n"
          "     command -n number outfile01 outfile02\n")


# Error message.
def err_message2():
    print("incorrect qualifier value!\n"
          "  Waited:\n"
          "     command -f infile outfile01 outfile02\n"
          "  Or:\n"
          "     command -n number outfile01 outfile02\n")


# ------------------------------------------------------------------------------
if __name__ == "__main__":
    argv = sys.argv
    argc = len(argv)

    if argc != 5:
        err_message1()
        exit(1)

    start = time.process_time()

    print("Start\n")

    container = Container()

    if argv[1] == "-f":
        container.in_file(argv[2])
    elif argv[1] == "-n":
        if (int(argv[2]) > 10000) or (int(argv[2]) < 1):
            print(f'incorrect number of figures! {argv[2]}.\n' \
                f'Set 0 < number <= 10000\n')
            exit(1)
        container.in_rnd(int(argv[2]))
    else:
        err_message2()
        exit(1)

    container.out(argv[3])
    container.sort()
    container.out(argv[4])

    container.clear()

    print("Stop\n")

    finish = time.process_time()
    elapsed_time = finish - start
    print('Time elapsed', str(elapsed_time) + "s")
