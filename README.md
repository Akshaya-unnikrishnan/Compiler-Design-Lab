# 📘 Compiler Design Lab Programs
This repository contains the complete set of Compiler Design laboratory experiments, including programs implemented using **LEX** and **YACC**, and additional theoretical compiler construction tasks.

---

## 🔧 Tools & Technologies Used
- **LEX / Flex**
- **YACC / Bison**
- **C Language**
- **GCC Compiler**
- **Ubuntu / Linux / Windows (with WSL or MinGW)**

---

## 🧪 List of Experiments
| No | Experiment Name | Tools |
|----|----------------|--------|
| 1 | Implement Lexical Analyzer using C | C |
| 2 | Implement Lexical Analyzer using LEX | LEX |
| 3 | Count number of lines, words & characters | LEX |
| 4 | Convert substring `abc` to `ABC` | LEX |
| 5 | Count vowels & consonants | LEX |
| 6 | Recognize valid arithmetic expression | LEX + YACC |
| 7 | Recognize a valid identifier | LEX + YACC |
| 8 | Calculator using LEX & YACC | LEX + YACC |
| 9 | NFA to DFA Conversion | C / Theory |
| 10 | Shift Reduce Parser | YACC |
| 11 | Constant Propagation | C |
| 12 | Intermediate Code Generation | C |
| 13 | Backend of Compiler | C |


---

## 📍 How to Run LEX & YACC Programs
### **Run LEX program**
```bash
lex filename.l
gcc lex.yy.c
./a.out
