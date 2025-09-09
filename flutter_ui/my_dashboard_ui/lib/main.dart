import 'package:flutter/material.dart';
import 'dart:convert';
import 'package:http/http.dart' as http;

void main(){
  runApp(MyApp());
}

class MyApp extends StatelessWidget{
  @override
  Widget build(BuildContext context){
    return MaterialApp(
      title: 'University Dashboard',
      theme: ThemeData(
        primarySwatch: Colors.blue,
      ),
      home: LoginScreen(),
    );
  }
}

class LoginScreen extends StatefulWidget{
  @override
  _LoginScreenState createState() => _LoginScreenState();

}

class _LoginScreenState extends State<LoginScreen>{
  final TextEditingController userController = TextEditingController();
  final TextEditingController passController = TextEditingController();

  Future<void> login() async {
    final userID = userController.text;
    final password = passController.text;

    final url = Uri.parse("http://127.0.0.1:8000/login"); // FastAPI URL

    try {
      final response = await http.post(
        url,
        headers: {"Content-Type": "application/json"},
        body: jsonEncode({"userID": userID, "password": password}),
      );

      if (response.statusCode == 200) {
        final data = jsonDecode(response.body);
        ScaffoldMessenger.of(context).showSnackBar(
          SnackBar(content: Text(data['message'])),
        );
      } else {
        final error = jsonDecode(response.body);
        ScaffoldMessenger.of(context).showSnackBar(
          SnackBar(content: Text(error['detail'])),
        );
      }
    } catch (e) {
      ScaffoldMessenger.of(context).showSnackBar(
        SnackBar(content: Text("Error: $e")),
      );
    }
  }

@override
Widget build(BuildContext context){
  return Scaffold(
    appBar: AppBar(title: Text("Login")),
    body: Padding(
      padding: EdgeInsets.all(16),
      child: Column(
        children: [
          TextField(
            controller : userController,
            decoration: InputDecoration(labelText: "UserID"),
          ),
          TextField(
            controller: passController,
            decoration: InputDecoration(labelText: "Password"),
            obscureText: true,
          ),
          SizedBox(height: 20),
          ElevatedButton(onPressed: login
            , child: Text("Sign in"),
          ),
        ],
      ),
    ),
  );
}

}



