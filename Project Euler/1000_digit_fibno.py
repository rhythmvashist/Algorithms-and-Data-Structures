
def limit_checker(number):
  if len(str(number)) < 1000:
    return True
  else:
    return False  

def get_fib_dynamic_prog():
  current = 0
  fib_number =[0,1]
  index = 2
  while current<10**999:
    current = fib_number[index-1]+fib_number[index-2]
    index = index+1
    fib_number.append(current)
    
  
  return index

def main():
  value = get_fib_dynamic_prog()
  print(value)

if __name__ == "__main__":
    main()

