class Student:
    pass


s1 = Student()

print(s1)
s1.name = 'festival'
s1.age = 23

print(s1.name)
print(getattr(s1,'name'))

class Stud:
    def __init__(self) -> None:
        self.name = 'sas'
        self.age =24

s2 = Stud()
print(s2)
print(s2.name)
s2.name = 'dsd'
print(s2.name)
print(s2.__dict__)



class Stude:

    def __init__(self):
        self.name = "Rohan"
        self.age = 20

    def print_student_details():
        print(self.name, end= " ")
        print(self.age)


s3 = Stude()
print(s3)
print(s3.name)
s3.print_student_details()
# s.print_student_details()

