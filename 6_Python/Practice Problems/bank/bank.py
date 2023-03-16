message = input("Greeting: ").strip()
if message.startswith('Hello'):
    print("$0")
elif message.startswith('H'):
    print("$20")
else:
    print("$100")