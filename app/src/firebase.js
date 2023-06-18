// Import the functions you need from the SDKs you need
import { initializeApp } from "firebase/app";
import { getDatabase } from "@firebase/database"
// TODO: Add SDKs for Firebase products that you want to use
// https://firebase.google.com/docs/web/setup#available-libraries

// Your web app's Firebase configuration
const firebaseConfig = {
  apiKey: "AIzaSyB2iGCEadrDLPOb72QrvW5vC2Kynnk11uE",
  authDomain: "vga-smart-signage---iot.firebaseapp.com",
  databaseURL: "https://vga-smart-signage---iot-default-rtdb.europe-west1.firebasedatabase.app",
  projectId: "vga-smart-signage---iot",
  storageBucket: "vga-smart-signage---iot.appspot.com",
  messagingSenderId: "736019854468",
  appId: "1:736019854468:web:991bf614b5bd7f44497ed1"
};

// Initialize Firebase
const app = initializeApp(firebaseConfig);
export const db = getDatabase(app);