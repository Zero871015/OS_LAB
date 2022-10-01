import string
import random

for i in range(50):
    print('"' + ''.join(random.choice(string.ascii_uppercase + string.digits) for _ in range(4)) + '",')
