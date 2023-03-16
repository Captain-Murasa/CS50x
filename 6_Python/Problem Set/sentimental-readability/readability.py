# TODO
def main():
    text = input("Text: ")
    grade = calculate_grade(count_letters(text), count_words(text), count_sentences(text))
    if grade < 1:
        print("Before Grade 1")
    elif grade > 16:
        print("Grade 16+")
    else:
        print(f"Grade: {grade}")


def count_letters(text):
    count = 0
    for i in text:
        if i.isalpha():
            count += 1
    return count


def count_words(text):
    count = 1
    for i in text:
        if i.isspace():
            count += 1
    return count


def count_sentences(text):
    count = 0
    for i in text:
        if i in ['.', '!', '?']:
            count += 1
    return count


def calculate_grade(letters, words, sentences):
    L = letters / words * 100
    S = sentences / words * 100
    return round(0.0588 * L - 0.296 * S - 15.8)


if __name__ == "__main__":
    main()