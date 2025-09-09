# Here the server related code


from fastapi import fastAPI 
from pydantic import BaseModel

app = FastAPI()

class LoginData(BaseModel):
    userID: str
    password: str


@app.post("/login")
def login(data: LoginData):
    if check_credentials(data.userID, data.password):
        return {"message": "Login Successful!"}
    return HTTPException(status_code=401, detail= "Invalid credentials, try again.")


def check_credentials(userID, password):
    with open("extra/users.csv", newline= '') as csvfile:
        reader = csv.DictReader(csvfile)
        for row in reader:
            if row['userID'] == userID and row['password'] == password:
                return True
    return False



if __name__ == '__main__':
  this_python_file = os.path.basename(__file__)[:-3]
  instance = uvicorn.run(f"{this_python_file}:app", host="127.0.0.1", port=8000, log_level="info", reload=True)
