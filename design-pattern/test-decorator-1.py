def bread(func):
    def wrapper():
        print("</''''\>")
        func()
        print("</____\>")
    return wrapper

def ingredients(func):
    def wrapper():
        print("#tomatoes#")
        func()
        print("~salad~")
    return wrapper

@bread
@ingredients
def sandwitch(food="--ham--"):
    print(food)

sandwitch()
