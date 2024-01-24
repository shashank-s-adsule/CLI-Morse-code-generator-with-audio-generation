# Morse CLI command



## setup
1. set your USER directory for `OUT_FILE_PATH` [ just replace `USER_NAME` with your `user name` ]
2. set the `SAVE_dir` path in `ending()` function:
   - for ***Windows System*** use `OUT_FILE_PATH[0]`  
   - for ***Linux System*** use `OUT_FILE_PATH[1]`
3. run the `morse.cpp` code once to get updated executable file. 

## execution
after geting the the executable file run this command on console
```console
.\morse.exe "YOUR TEXT"
```
this command will work for only single line text.

for multiline text save the data into .txt and pass the file path to the console
```console
.\morse.exe -r "FILE_PATH"
```
[ NOTE: among `-r` `READTXT` `readtxt` `Readtxt` any one can be used ]

after execution the results can be saved to your `Downloads` folder with a user command `[y/n]`.


[ NOTE: for ***Linux System*** use `./morse` commnd on terminal ]


## Limitations 
1. some charater are not print like " 