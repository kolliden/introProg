# Computer Science Intro to Programming

## Table of Contents

- [About](#about)
- [Getting Started](#getting_started)
- [Usage](#usage)
- [Contributing](../CONTRIBUTING.md)

## About <a name="about"></a>

This repository contains the materials and assignments for the introductory programming course. The course covers basic programming concepts and provides hands-on experience through various exercises and assignments.

## Getting Started <a name="getting_started"></a>

These instructions will help you set up the project on your local machine for development and testing purposes. See [deployment](#deployment) for notes on how to deploy the project on a live system.

### Prerequisites

You will need the following software installed on your machine:

- A C compiler (e.g., `gcc`)
- A code editor (e.g., Visual Studio Code)

### Installing

Follow these steps to set up your development environment:

1. **Clone the repository:**
    ```sh
    git clone https://github.com/yourusername/your-repo.git
    cd your-repo
    ```

2. **Open the project in Visual Studio Code:**
    ```sh
    code .
    ```

3. **Compile an example program:**
    ```sh
    gcc -o hello 14.10.24/hello.c
    ```

4. **Run the compiled program:**
    ```sh
    ./hello
    ```

## Usage <a name="usage"></a>

The repository is organized by date, with each folder containing exercises (`_Aufgaben`) and practice problems (`_Uebungen`). Navigate to the appropriate directory to find the relevant files.

### Example

To run the example program from `14.10.24`:

1. Navigate to the directory:
    ```sh
    cd 14.10.24
    ```

2. Compile the program:
    ```sh
    gcc -o hello hello.c
    ```

3. Run the program:
    ```sh
    ./hello
    ```

### Detailed Directory Structure

- **14.10.24/**: Contains the initial example program `hello.c`.
- **15.10.24/**: Contains the first set of exercises (`01_Aufgaben`) and practice problems (`01_Uebungen`).
- **16.10.24/**: Contains the second set of exercises (`02_Aufgaben`) and practice problems (`02_Uebungen`).
- **17.10.24/**: Contains the third set of exercises (`03_Aufgaben`) and practice problems (`03_Uebungen`).
- **18.10.24/**: Contains the fourth set of exercises (`04_Aufgaben`) and practice problems (`04_Uebungen`).
- **21.10.24/**: Contains the fifth set of exercises (`05_Aufgaben`) and practice problems (`05_Uebungen`).
- **22.10.24/** to **25.10.24/**: Reserved for future exercises and practice problems.

## Contributing

Please read [CONTRIBUTING.md](../CONTRIBUTING.md) for details on our code of conduct and the process for submitting pull requests.

## Deployment <a name="deployment"></a>

For deployment on a live system, ensure that all dependencies are installed and the environment is properly configured. Follow the installation steps to set up the project on the target machine.
