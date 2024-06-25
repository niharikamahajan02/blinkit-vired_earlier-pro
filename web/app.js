const express = require('express');
const bodyParser = require('body-parser');
const session = require('express-session');
const multer = require('multer');
const path = require('path');
const fs = require('fs');

const app = express();
const port = 3000;

// Middleware
app.use(bodyParser.urlencoded({ extended: true }));
app.use(bodyParser.json());
app.use(session({ secret: 'your-secret-key', resave: true, saveUninitialized: true }));

// In-memory storage
const users = [];
const uploadDir = path.join(__dirname, 'uploads');

// Create the uploads directory if it doesn't exist
if (!fs.existsSync(uploadDir)) {
    fs.mkdirSync(uploadDir);
}

// Multer configuration for file upload
const storage = multer.memoryStorage();
const upload = multer({ storage: storage });

// Routes
app.get('/', (req, res) => {
    res.sendFile(path.join(__dirname, 'index.html'));
});

app.post('/signup', (req, res) => {
    const { username, password } = req.body;
    // Check if the user already exists
    if (!users.find(user => user.username === username)) {
        users.push({ username, password });
        // Create a folder for the user's uploads
        const userUploadDir = path.join(uploadDir, username);
        if (!fs.existsSync(userUploadDir)) {
            fs.mkdirSync(userUploadDir);
        }
        req.session.username = username;
        res.redirect('/dashboard');
    } else {
        res.send('User already exists');
    }
});

app.post('/login', (req, res) => {
    const { username, password } = req.body;
    const user = users.find(user => user.username === username && user.password === password);
    if (user) {
        req.session.username = username;
        res.redirect('/dashboard');
    } else {
        res.send('Invalid username or password');
    }
});

app.get('/dashboard', (req, res) => {
    if (req.session.username) {
        res.sendFile(path.join(__dirname, 'dashboard.html'));
    } else {
        res.redirect('/');
    }
});

app.post('/upload', upload.single('image'), (req, res) => {
    if (req.session.username && req.file) {
        const userUploadDir = path.join(uploadDir, req.session.username);
        const fileName = `${Date.now()}_${req.file.originalname}`;
        const filePath = path.join(userUploadDir, fileName);
        
        fs.writeFileSync(filePath, req.file.buffer);
        
        res.send('Image uploaded successfully');
    } else {
        res.redirect('/');
    }
});

app.listen(port, () => {
    console.log(`Server is running on http://localhost:${port}`);
});
