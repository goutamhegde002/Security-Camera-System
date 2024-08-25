import 'package:flutter/material.dart';
import 'package:http/http.dart' as http;

void main() {
  runApp(MyApp());
}

class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: AlertScreen(),
    );
  }
}

class AlertScreen extends StatelessWidget {
  final String serverUrl = 'http://your_server_url';

  Future<void> fetchAlerts() async {
    final response = await http.get(Uri.parse(serverUrl));
    if (response.statusCode == 200) {
      // Handle the response
    } else {
      // Handle errors
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: Text('Security Alerts')),
      body: Center(
        child: ElevatedButton(
          onPressed: fetchAlerts,
          child: Text('Check Alerts'),
        ),
      ),
    );
  }
}
