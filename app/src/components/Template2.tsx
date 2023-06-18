import * as React from 'react';
import Button from '@mui/material/Button';
import TextField from '@mui/material/TextField';
import Box from '@mui/material/Box';
import { ThemeProvider } from '@emotion/react';
import { Container, CssBaseline, Typography, createTheme } from '@mui/material';

export interface Template2Props {
    setShowTemplate2: React.Dispatch<React.SetStateAction<boolean>>;
  }
  
  export const Template2: React.FC<Template2Props> = ({
    setShowTemplate2
  }) => {

    const handleOnGoBackClick = () => {
        setShowTemplate2(false);
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
            Create Your Signage - Template 2
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
            />
            <TextField
              margin="normal"
              //required
              fullWidth
              name="Task1"
              label="Task 1"
              type="Task1"
              id="Task1"
            />
            <TextField
              margin="normal"
              //required
              fullWidth
              name="Task2"
              label="Task 2"
              type="Task2"
              id="Task2"
            />
            <TextField
              margin="normal"
              //required
              fullWidth
              name="Task3"
              label="Task 3"
              type="Task3"
              id="Task3"
            />
            <TextField
              margin="normal"
             // required
              fullWidth
              name="Task4"
              label="Task 4"
              type="Task4"
              id="Task4"
            />

            <Button
              type="submit"
              fullWidth
              variant="contained"
              sx={{ mt: 3, mb: 2 }}
              //onClick={handleOnLoginClick}
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