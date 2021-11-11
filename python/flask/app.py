from flask import Flask,render_template,request,redirect

app = Flask(__name__)
@app.route('/', methods=("GET", "POST"))
def input():
    if request.method == "GET":

        return render_template('ht.html')
    if request.method == "POST":
        return redirect("/login")
@app.route('/<name>')
def getname(name):

    return name

@app.route("/login", methods=("GET", "POST"))
def login():
  # GET请求
    if request.method == "GET":
        return render_template("login.html")
  # POST请求
    if request.method == "POST":

        user_info = request.form.to_dict()
        print(user_info)
        if "admin" == user_info.get("username")   and '123456'  == user_info.get("password") :
            return redirect("/new")
    print(request.form.to_dict())
 
    return "用户名密码错误"
    
if __name__ == "__main__":
    app.run()