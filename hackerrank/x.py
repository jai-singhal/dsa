# importing python fire module
import fire

# defining a function
def hello(name):
  return 'Hello {0}, Have a nice day {0}'.format(name)

if __name__ == '__main__':
    # converting our fucntion in a Command Line Interface (CLI).
  fire.Fire(hello)