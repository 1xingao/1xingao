import shutil

path = "C:\\Users\\藏起来的十七\\.idl"

try:
    shutil.rmtree(path)
except OSError as e:
    print(e)
else:
    print("The directory is deleted successfully")
