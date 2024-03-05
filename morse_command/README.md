# Morse CLI command
This is an basic ***text to morse & morse to text*** convertion command code Writen in C++.

it runs directy on terminal by giving user arguments.

list of character to Morse mapping: 

|Char|Morse|Number|Morse|Symbol|Morse
| :-----: | :-----: | :----:| :----:|:----:| :----:|
| (A,a) | .- |1|.----|. | .-.-.-|
| (B,b) | -... |2|..---|, | --..--|
| (C,c) | -.-. |3|...--|? | ..--..|
| (D,d) | -.. |4|....-|\ | .----.|
| (E,e) | .	   |5|.....|! | -.-.--|
| (F,f) | ..-. |6|-....|/ | -..-.|
| (G,g) | --. |7|--...|( | -.--.|
| (H,h) | .... |8|---..|) | -.--.-|
| (I,i) | .. |9|----.|& | .-...|
| (J,j) | .--- |0|-----|: | ---...|
| (K,k) | -.- ||| ; | -.-.-.|
| (L,l) | .-.. ||| = | -...-|
| (M,m) | -- ||| + | .-.-.|
| (N,n) | -. ||| - | -....-|
| (O,o) | --- ||| _ | ..--.-|
| (P,p) | .--. ||| \ | .-..-.|
| (Q,q) | --.- ||| $ | ...-..-|
| (R,r) | .-. ||| @ | .--.-.|
| (S,s) | --- ||| SPACE| .......|
| (T,t) | - |
| (U,u) | ..- |
| (V,v) | ...- |
| (W,w) | .-- |
| (X,x) | -..- |
| (Y,y) | -.-- |
| (Z,z) | --.. |


## Setup
1. Set your USER directory for [`OUT_FILE_PATH`](./morse.cpp) [ just replace `USER_NAME` with your `user name` ]
2. Set the `SAVE_dir` path in `ending()` function:
   - For ***Windows System*** use `OUT_FILE_PATH[0]`  
   - For ***Linux System*** use `OUT_FILE_PATH[1]`
3. Run the `morse.cpp` code once to get updated executable file. 

## Execution
After geting the the executable file run this command on console
```console
.\morse.exe "YOUR TEXT"
```
This command will work for only single line text.

For multiline text save the data into .txt and pass the file path to the console
```console
.\morse.exe -r "FILE_PATH"
```
[ NOTE: among `-r` `READTXT` `readtxt` `Readtxt` any one can be used ]

After execution the results can be saved to your `Downloads` folder with a user command `[y/n]`.


[ NOTE: for ***Linux System*** use `./morse` commnd on terminal ]


## Limitations 
1. Some character are not printed in morse code: ``` ", `, ~, #, %, ^, *, <, >, [, ], {, }, |, \```
2. Output file will have whole output as a single line [no new line]
