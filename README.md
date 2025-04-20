# myString - Enhanced String Utility Class
A powerful C++ string utility class that extends standard string functionality with advanced manipulation and analysis features.

## Features

### Core String Operations
- Store and manage string values
- Get/set string content
- Count words and characters
- Split and join strings

### Text Analysis
- **Vowel operations**:
  - Count vowels in text
  - Extract and print vowels
- **Character analysis**:
  - Count specific characters
  - Differentiate between upper/lower case
  - Check character properties

### Text Transformation
- **Case modification**:
  - Capitalize/lowercase first letters
  - Convert entire string to upper/lower case
  - Invert character cases
- **Text cleaning**:
  - Trim whitespace (left/right/both)
  - Remove punctuation
- **Text manipulation**:
  - Reverse word order
  - Replace words/substrings

### Advanced Features
- Multiple splitting/joining options
- Case-sensitive/insensitive operations
- Configurable trimming behavior
- Word-level operations

## Usage

### Common Operations
```cpp
// Count vowels
int vowels = str.countVowel();

// Uppercase first letters
string titled = str.upperFirstLetter();

// Split into words
vector<string> words = str.split();

// Remove punctuation
string clean = str.removePunctuation();
```

### Static Methods
```cpp
// Use methods without instantiating
string reversed = myString::reverseWord("Hello World");
int wordCount = myString::countWord("This is a sentence");
```

### Capitalizing a Sentence
```cpp
myString sentence("hello world");
cout << sentence.upperFirstLetter(); // Outputs: "Hello World"
```

### Reversing Word Order
```cpp
string reversed = myString::reverseWord("The quick brown fox");
// Outputs: "fox brown quick The"
```

### Cleaning User Input
```cpp
myString userInput("  This, has punctuation!  ");
string clean = userInput.trim().removePunctuation();
// Results: "This has punctuation"
```

## License
Open source - free to use.
