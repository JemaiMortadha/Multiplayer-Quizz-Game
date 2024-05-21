# Multiplayer Quiz Game

This repository contains a C application for a multiplayer quiz game. Two players can compete by answering randomly selected questions from a file. The player with the most correct answers at the end of the game wins.

## Features

- Multiplayer support (two players)
- Randomly selected questions
- Shuffled answers for each question
- Score tracking and winner announcement

## Getting Started

### Prerequisites

- C compiler (such as GCC)
- Basic knowledge of C programming

### Installation

1. Clone the repository:
   ```sh
   git clone https://github.com/JemaiMortadha/Multiplayer-Quizz-Game.git
   cd Multiplayer-Quizz-Game
   ```

2. Ensure you have a file named `q.txt` in the same directory as the source code. The file should contain questions and answers in the following format:
   ```
   Question1/Answer1/Answer2/Answer3
   Question2/Answer1/Answer2/Answer3
   ...
   ```

### Compiling the Application

1. Compile the application using a C compiler:
   ```sh
   gcc -o quiz_game quiz_game.c
   ```

### Running the Application

1. Run the compiled application:
   ```sh
   ./quiz_game
   ```

## Usage

Upon running the application, each player will be presented with a series of questions. They will choose an answer by typing `a`, `b`, or `c`. The game will keep track of the scores and announce the winner at the end.

### Sample Output

```
Player 1 - Question 1: What is the capital of France?
a) Paris
b) London
c) Berlin
Choose an answer (a, b, c): a

Player 2 - Question 1: What is the capital of Germany?
a) Berlin
b) Paris
c) Madrid
Choose an answer (a, b, c): a

...

Game Over!

Player 1's Score: 3
Player 2's Score: 2

Player 1 is the winner!
```

## Project Structure

- `quiz_game.c`: The main source code file for the quiz game.

## Contributing

Contributions are welcome! Please create a pull request or open an issue to discuss any changes.

## License

This project is licensed under the MIT License. See the `LICENSE` file for details.

## Contact

For any inquiries or feedback, please contact [jemaimortadha@gmail.com](mailto:jemaimortadha@gmail.com).
