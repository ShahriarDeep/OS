<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Login Page</title>
</head>
<body>
  <h2>Login Form</h2>
  <input type="text" id="userId" placeholder="Enter ID"><br><br>
  <input type="password" id="password" placeholder="Enter Password"><br><br>
  <button id="loginBtn">Login</button>
  <p id="message"></p>

  <script src="./index.js"></script>
</body>
</html>



// Save correct ID and password
const correctId = 'admin';
const correctPassword = '1234';

// Get input fields and message paragraph
const idInput = document.getElementById('userId');
const passInput = document.getElementById('password');
const message = document.getElementById('message');
const button = document.getElementById('loginBtn');

// Add click event to button
button.addEventListener('click', function () {
  const enteredId = idInput.value;
  const enteredPass = passInput.value;

  if (enteredId === correctId && enteredPass === correctPassword) {
    message.innerText = 'Login successful';
    message.style.color = 'green';
  } else {
    message.innerText = 'Invalid ID or Password';
    message.style.color = 'red';
  }
});