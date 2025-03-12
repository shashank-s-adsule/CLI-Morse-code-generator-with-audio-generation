# Morse CLI Command With Audio Generation 
This is an basic ***text to morse & morse to text*** convertion command code Writen in C++ which can also generate equivalent morse audio output.

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
1. Run the [`morse.cpp`](./morse.cpp) code once to get updated executable file. 

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
>[!NOTE]\
>among `-r` `READTXT` `readtxt` `Readtxt` any one can be used

After execution the results can be saved to your `Downloads/Morse` folder with a user command `[y/n]`.

>[!NOTE]\
>for ***Linux System*** use `./morse` commnd on terminal


## Limitations 
1. Some character are not printed in morse code: ``` ", `, ~, #, %, ^, *, <, >, [, ], {, }, |, \```
2. Output file will have whole output as a single line [no new line]

## Experimentation
1. if facing an error with folder or saving file, please check [`USERNAME`](morse.cpp#L13) and change it as per your preference
2. To change the default save directory, you can modify the string [`OUT_FILE_PATH`](morse.cpp#L59) as needed
3. The default audio duration is given below. Change it if required.

|Variables|default time|
|:--:|:--:|
|[`DOT_DURATION`](audio_genrator.h#L16)| 0.1s|
|[`DASH_DURATION`](audio_genrator.h#L17)| 0.3s|
|[`INTER_ELEMENT_GAP`](audio_genrator.h#L18)| 0.125s|
|[`INTER_LETTER_GAP`](audio_genrator.h#L100)| 0.2s|
|[`White Space`](audio_genrator.h#L71)| 0.75s|

# Sample Example
Sample Input:  `hello world`<br>
Sample Output: `.... . .-.. .-.. --- ....... .-- --- .-. .-.. -..` <br>
Sample WAV output:<br>

<audio controls>
    <source src="https://raw.githubusercontent.com/shashank-s-adsule/CLI-Morse-code-generator-with-audio-generation/raw/refs/heads/main/assets/example.wav" type="audio/wav">
    Your browser Does Not support .WAV audio element
</audio>