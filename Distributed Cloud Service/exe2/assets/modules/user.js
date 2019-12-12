
class User {

    constructor(name , password , type) {
        this.name = name ;
        this.password = password;
        this.type = type;
    }

    authenticate(name, password){
        return (this.name == name && this.password == password);
    }

}

module.exports = User;