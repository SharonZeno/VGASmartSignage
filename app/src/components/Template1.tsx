import * as React from 'react';
import Button from '@mui/material/Button';
import TextField from '@mui/material/TextField';
import Box from '@mui/material/Box';
import { ThemeProvider } from '@emotion/react';
import { Container, CssBaseline, Typography, createTheme } from '@mui/material';
import { ref, set } from "@firebase/database";
import { db } from "../firebase"

export interface Template1Props {
  setShowTemplate1: React.Dispatch<React.SetStateAction<boolean>>;
}

export const Template1: React.FC<Template1Props> = ({
  setShowTemplate1
}) => {
   
  const handleSubmit = (e: any) => {
    setShowTemplate1(false);
    e.preventDefault();
    set( ref(db, "template1" ) , {
    MainHeadline: mainHeadline,
    Task1: task1,
    Task2: task2,
    Task3: task3,
    Task4: task4
  });  
  }
  


  const handleOnGoBackClick = () => {
    setShowTemplate1(false);
}

    const [mainHeadline, setMainHeadline] = React.useState<string>('');
    const [task1, setTask1] = React.useState<string>('');
    const [task2, setTask2] = React.useState<string>('');
    const [task3, setTask3] = React.useState<string>('');
    const [task4, setTask4] = React.useState<string>('');

    const handleMainHeadlineChange = (e: React.ChangeEvent<HTMLInputElement>) => {
      e.preventDefault();
      setMainHeadline(e.target.value); 
  }

  const handleTask1Change = (e: React.ChangeEvent<HTMLInputElement>) => {
    e.preventDefault();
    setTask1(e.target.value); 
}

const handleTask2Change = (e: React.ChangeEvent<HTMLInputElement>) => {
  e.preventDefault();
  setTask2(e.target.value); 
}

const handleTask3Change = (e: React.ChangeEvent<HTMLInputElement>) => {
  e.preventDefault();
  setTask3(e.target.value); 
}

const handleTask4Change = (e: React.ChangeEvent<HTMLInputElement>) => {
  e.preventDefault();
  setTask4(e.target.value); 
}

    const theme = createTheme();
    return (
    <ThemeProvider theme={theme}>
       <Box 
                m={1} //margin
                display="flex"
                justifyContent="flex-start"
                alignItems="flex-start">
                <div>
                <Button variant="outlined" size="small" onClick={handleOnGoBackClick} sx={{borderColor: "#92ACAD", color: "#92ACAD"}}>
                go back
                </Button>
                </div>    
        </Box>
        <Container component="main" maxWidth="xs">
        <CssBaseline />
        <Box
          sx={{
            marginTop: 8,
            display: 'flex',
            flexDirection: 'column',
            alignItems: 'center',
          }}
        >
          <Typography component="h1" variant="h5">
            Create Your Signage - Template 1
          </Typography>
          <div>
          <Box component="form" noValidate sx={{ mt: 1 }}>
          <TextField
              margin="normal"
              //required
              fullWidth
              name="MainHeadline"
              label="Main Headline"
              type="MainHeadline"
              id="MainHeadline"
              onChange={handleMainHeadlineChange}
            />
            <TextField
              margin="normal"
              //required
              fullWidth
              name="Task1"
              label="Task 1"
              type="Task1"
              id="Task1"
              onChange={handleTask1Change}
            />
            <TextField
              margin="normal"
              //required
              fullWidth
              name="Task2"
              label="Task 2"
              type="Task2"
              id="Task2"
              onChange={handleTask2Change}
            />
            <TextField
              margin="normal"
              //required
              fullWidth
              name="Task3"
              label="Task 3"
              type="Task3"
              id="Task3"
              onChange={handleTask3Change}
            />
            <TextField
              margin="normal"
             // required
              fullWidth
              name="Task4"
              label="Task 4"
              type="Task4"
              id="Task4"
              onChange={handleTask4Change}
            />

            <Button
              type="submit"
              fullWidth
              variant="contained"
              sx={{ mt: 3, mb: 2 }}
              onClick={handleSubmit}
            >
              Submit
            </Button>
        </Box>
        </div>
        </Box>
      </Container>
        </ThemeProvider>
    )
};