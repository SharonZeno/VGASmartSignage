import * as React from 'react';
import Button from '@mui/material/Button';
import TextField from '@mui/material/TextField';
import Box from '@mui/material/Box';
import { ThemeProvider } from '@emotion/react';
import { AppBar, Card, CardActions, CardContent, CardHeader, Collapse, Container, CssBaseline, Grid, IconButton, MenuItem, Toolbar, Typography, createTheme } from '@mui/material';
import { ref, set } from "@firebase/database";
import { db } from "../firebase";
import logo from './logo.jpg';
import { ArrowDropDown } from '@mui/icons-material';

const colors = [
  {
    value: 'RED',
  },
  {
    value: 'GREEN',
  },
  {
    value: 'BLUE',
  },
  {
    value: 'YELLOW',
  },
];

export interface Template2Props {
  setShowTemplate2: React.Dispatch<React.SetStateAction<boolean>>;
  controller: string;
}

export const Template2: React.FC<Template2Props> = ({
  setShowTemplate2,controller
}) => {
   
  const handleSubmit = (e: any) => {
    setShowTemplate2(false);
    e.preventDefault();
    set( ref(db, controller ) , {
        template: 2,
        MainHeadline: mainHeadline,
        FirstFloorHeadline: firstFloorHeadline,
        FirstFloorClassDesc1: firstFloorClassDesc1,
        FirstFloorClassDesc2: firstFloorClassDesc2,
        FirstFloorClassDesc3: firstFloorClassDesc3,
        FirstFloorClassDesc4: firstFloorClassDesc4,
        FirstFloorBackgroundColor: firstFloorBackgroundColor,
        SecondFloorHeadline: secondFloorHeadline,
        SecondFloorClassDesc1: secondFloorClassDesc1,
        SecondFloorClassDesc2: secondFloorClassDesc2,
        SecondFloorClassDesc3: secondFloorClassDesc3,
        SecondFloorClassDesc4: secondFloorClassDesc4,
        SecondFloorBackgroundColor: secondFloorBackgroundColor,
        ThirdFloorHeadline: thirdFloorHeadline,
        ThirdFloorClassDesc1: thirdFloorClassDesc1,
        ThirdFloorClassDesc2: thirdFloorClassDesc2,
        ThirdFloorClassDesc3: thirdFloorClassDesc3,
        ThirdFloorClassDesc4: thirdFloorClassDesc4,
        ThirdFloorBackgroundColor: thirdFloorBackgroundColor,
  });  
  }
  


  const handleOnGoBackClick = () => {
    setShowTemplate2(false);
}

    const [mainHeadline, setMainHeadline] = React.useState<string>('');

    const [firstFloorHeadline, setFirstFloorHeadline] = React.useState<string>('');
    const [firstFloorClassDesc1, setFirstFloorClassDesc1] = React.useState<string>('');
    const [firstFloorClassDesc2, setFirstFloorClassDesc2] = React.useState<string>('');
    const [firstFloorClassDesc3, setFirstFloorClassDesc3] = React.useState<string>('');
    const [firstFloorClassDesc4, setFirstFloorClassDesc4] = React.useState<string>('');
    const [firstFloorBackgroundColor, setFirstFloorBackgroundColor] = React.useState<string>('');

    const [secondFloorHeadline, setSecondFloorHeadline] = React.useState<string>('');
    const [secondFloorClassDesc1, setSecondFloorClassDesc1] = React.useState<string>('');
    const [secondFloorClassDesc2, setSecondFloorClassDesc2] = React.useState<string>('');
    const [secondFloorClassDesc3, setSecondFloorClassDesc3] = React.useState<string>('');
    const [secondFloorClassDesc4, setSecondFloorClassDesc4] = React.useState<string>('');
    const [secondFloorBackgroundColor, setSecondFloorBackgroundColor] = React.useState<string>('');

    const [thirdFloorHeadline, setThirdFloorHeadline] = React.useState<string>('');
    const [thirdFloorClassDesc1, setThirdFloorClassDesc1] = React.useState<string>('');
    const [thirdFloorClassDesc2, setThirdFloorClassDesc2] = React.useState<string>('');
    const [thirdFloorClassDesc3, setThirdFloorClassDesc3] = React.useState<string>('');
    const [thirdFloorClassDesc4, setThirdFloorClassDesc4] = React.useState<string>('');
    const [thirdFloorBackgroundColor, setThirdFloorBackgroundColor] = React.useState<string>('');

    const [expand1, setExpand1] = React.useState<boolean>(false);
    const [expand2, setExpand2] = React.useState<boolean>(false);
    const [expand3, setExpand3] = React.useState<boolean>(false);

    const handleMainHeadlineChange = (e: React.ChangeEvent<HTMLInputElement>) => {
      e.preventDefault();
      setMainHeadline(e.target.value); 
  }

  const handleFirstFloorHeadline = (e: React.ChangeEvent<HTMLInputElement>) => {
    e.preventDefault();
    setFirstFloorHeadline(e.target.value); 
}

const handleFirstFloorClassDesc1 = (e: React.ChangeEvent<HTMLInputElement>) => {
  e.preventDefault();
  setFirstFloorClassDesc1(e.target.value); 
}

const handleFirstFloorClassDesc2 = (e: React.ChangeEvent<HTMLInputElement>) => {
  e.preventDefault();
  setFirstFloorClassDesc2(e.target.value); 
}

const handleFirstFloorClassDesc3 = (e: React.ChangeEvent<HTMLInputElement>) => {
  e.preventDefault();
  setFirstFloorClassDesc3(e.target.value); 
}

const handleFirstFloorClassDesc4 = (e: React.ChangeEvent<HTMLInputElement>) => {
  e.preventDefault();
  setFirstFloorClassDesc4(e.target.value); 
}

const handleFirstFloorBackgroundColorChange = (e: React.ChangeEvent<HTMLInputElement>) => {
  e.preventDefault();
  setFirstFloorBackgroundColor(e.target.value); 
}

const handleSecondFloorHeadline = (e: React.ChangeEvent<HTMLInputElement>) => {
  e.preventDefault();
  setSecondFloorHeadline(e.target.value); 
}

const handleSecondFloorClassDesc1 = (e: React.ChangeEvent<HTMLInputElement>) => {
e.preventDefault();
setSecondFloorClassDesc1(e.target.value); 
}

const handleSecondFloorClassDesc2 = (e: React.ChangeEvent<HTMLInputElement>) => {
e.preventDefault();
setSecondFloorClassDesc2(e.target.value); 
}

const handleSecondFloorClassDesc3 = (e: React.ChangeEvent<HTMLInputElement>) => {
e.preventDefault();
setSecondFloorClassDesc3(e.target.value); 
}

const handleSecondFloorClassDesc4 = (e: React.ChangeEvent<HTMLInputElement>) => {
e.preventDefault();
setSecondFloorClassDesc4(e.target.value); 
}

const handleSecondFloorBackgroundColorChange = (e: React.ChangeEvent<HTMLInputElement>) => {
  e.preventDefault();
  setSecondFloorBackgroundColor(e.target.value); 
}

const handleThirdFloorHeadline = (e: React.ChangeEvent<HTMLInputElement>) => {
  e.preventDefault();
  setThirdFloorHeadline(e.target.value); 
}

const handleThirdFloorClassDesc1 = (e: React.ChangeEvent<HTMLInputElement>) => {
e.preventDefault();
setThirdFloorClassDesc1(e.target.value); 
}

const handleThirdFloorClassDesc2 = (e: React.ChangeEvent<HTMLInputElement>) => {
e.preventDefault();
setThirdFloorClassDesc2(e.target.value); 
}

const handleThirdFloorClassDesc3 = (e: React.ChangeEvent<HTMLInputElement>) => {
e.preventDefault();
setThirdFloorClassDesc3(e.target.value); 
}

const handleThirdFloorClassDesc4 = (e: React.ChangeEvent<HTMLInputElement>) => {
e.preventDefault();
setThirdFloorClassDesc4(e.target.value); 
}

const handleThirdFloorBackgroundColorChange = (e: React.ChangeEvent<HTMLInputElement>) => {
  e.preventDefault();
  setThirdFloorBackgroundColor(e.target.value); 
}

    const theme = createTheme();
    return (
      <ThemeProvider theme={theme}>
        <Box sx={{ flexGrow: 1 } }>
          <AppBar position="static" sx={{background: "#60829D"}}>
            <Toolbar>
              <img src={logo} alt="" width={50}/>
                <Box sx={{ flexGrow: 1 }} />
                <Box sx={{ display: { xs: 'none', md: 'flex' }, gap: 1}}>
                    <Button 
                      variant="outlined" 
                      size="medium" 
                      onClick={handleOnGoBackClick} 
                      sx={{borderColor: "white", color: "white"}}>
                          Go Back
                      </Button>
                </Box>
            </Toolbar>
         </AppBar>
        </Box>
        <Container maxWidth="md" component="main">
          <CssBaseline />
          <Box
            sx={{
              marginTop: 8,
              display: 'flex',
              flexDirection: 'column',
              alignItems: 'center',
            }}>
            <Typography component="h1" variant="h5">
              Create Your Signage - Template 2
            </Typography>
          </Box>
          <br></br>
          <Box component="form" noValidate sx={{ mt: 1 }}>
              <TextField
                  style = {{width: 300}}
                  margin="normal"
                  fullWidth
                  name="MainHeadline"
                  label="Main Headline"
                  type="MainHeadline"
                  id="MainHeadline"
                  onChange={handleMainHeadlineChange}
                />
          </Box>
          <br></br>
          <Grid container spacing={5} alignItems="flex-end">
            <Grid
                item
                xs={12}
                sm={8}
                md={4}
              >
                <br></br>
                <Card>
                <CardHeader
                  title="First Floor Details"
                  titleTypographyProps={{ align: 'center' }}
                  sx={{
                    backgroundColor: (theme) =>
                      theme.palette.mode === 'light'
                        ? theme.palette.grey[200]
                        : theme.palette.grey[700],
                  }}
                />
                <CardActions>
                  <Grid container alignItems="center" justifyContent="center">
                     <IconButton onClick={() => setExpand1(!expand1)}>
                        <ArrowDropDown/>
                     </IconButton>
                  </Grid>
                </CardActions>
                <Collapse in={expand1}>
                <CardContent>
                <Box component="form" noValidate sx={{ mt: 1 }}>
                  <TextField
                      margin="normal"
                      fullWidth
                      name="firstFloorHeadline"
                      label="Floor Headline"
                      type="firstFloorHeadline"
                      id="firstFloorHeadline"
                      onChange={handleFirstFloorHeadline}
                    />
                  <TextField
                    margin="normal"
                    fullWidth
                    name="firstFloorClassDesc1"
                    label="Class Description"
                    type="firstFloorClassDesc1"
                    id="firstFloorClassDesc1"
                    onChange={handleFirstFloorClassDesc1}
                  />
                  <TextField
                    margin="normal"
                    //required
                    fullWidth
                    name="firstFloorClassDesc2"
                    label="Class Description"
                    type="firstFloorClassDesc2"
                    id="firstFloorClassDesc2"
                    onChange={handleFirstFloorClassDesc2}
                  />
                  <TextField
                    margin="normal"
                    fullWidth
                    name="firstFloorClassDesc3"
                    label="Class Description"
                    type="firstFloorClassDesc3"
                    id="firstFloorClassDesc3"
                    onChange={handleFirstFloorClassDesc3}
                  />
                  <TextField
                    margin="normal"
                    fullWidth
                    name="firstFloorClassDesc4"
                    label="Class Description"
                    type="firstFloorClassDesc4"
                    id="firstFloorClassDesc4"
                    onChange={handleFirstFloorClassDesc4}
                  />
                  <TextField
                    margin="normal"
                    fullWidth
                    id="filled-select-color"
                    select
                    helperText="first floor background color"
                    variant="filled"
                    onChange={handleFirstFloorBackgroundColorChange}
                  >
                    {colors.map((option) => (
                      <MenuItem key={option.value} value={option.value}>
                        {option.value}
                      </MenuItem>
                    ))}
                  </TextField>
                </Box>
                </CardContent>
                </Collapse>
                </Card>
            </Grid>
            <Grid
                item
                xs={12}
                sm={8}
                md={4}
              >
              <br></br>
              <Card>
              <CardHeader
                  title="Second Floor Details"
                  // subheader="sub"
                  titleTypographyProps={{ align: 'center' }}
                  // subheaderTypographyProps={{
                  //   align: 'center',
                  // }}
                  sx={{
                    backgroundColor: (theme) =>
                      theme.palette.mode === 'light'
                        ? theme.palette.grey[200]
                        : theme.palette.grey[700],
                  }}
                />
                 <CardActions>
                  <Grid container alignItems="center" justifyContent="center">
                     <IconButton onClick={() => setExpand2(!expand2)}>
                        <ArrowDropDown/>
                     </IconButton>
                  </Grid>
                </CardActions>
                <Collapse in={expand2}>
              <CardContent>
              <Box component="form" noValidate sx={{ mt: 1 }}>
                  <TextField
                    margin="normal"
                    fullWidth
                    name="secondFloorHeadline"
                    label="Floor Headline"
                    type="secondFloorHeadline"
                    id="secondFloorHeadline"
                    onChange={handleSecondFloorHeadline}
                  />
                  <TextField
                    margin="normal"
                    fullWidth
                    name="secondFloorClassDesc1"
                    label="Class Description"
                    type="secondFloorClassDesc1"
                    id="secondFloorClassDesc1"
                    onChange={handleSecondFloorClassDesc1}
                  />
                  <TextField
                    margin="normal"
                    //required
                    fullWidth
                    name="secondFloorClassDesc2"
                    label="Class Description"
                    type="secondFloorClassDesc2"
                    id="secondFloorClassDesc2"
                    onChange={handleSecondFloorClassDesc2}
                  />
                  <TextField
                    margin="normal"
                    fullWidth
                    name="secondFloorClassDesc3"
                    label="Class Description"
                    type="secondFloorClassDesc3"
                    id="secondFloorClassDesc3"
                    onChange={handleSecondFloorClassDesc3}
                  />
                  <TextField
                    margin="normal"
                    fullWidth
                    name="secondFloorClassDesc4"
                    label="Class Description"
                    type="secondFloorClassDesc4"
                    id="secondFloorClassDesc4"
                    onChange={handleSecondFloorClassDesc4}
                  />
                  <TextField
                    margin="normal"
                    fullWidth
                    id="filled-select-color"
                    select
                    helperText="second floor background color"
                    variant="filled"
                    onChange={handleSecondFloorBackgroundColorChange}
                  >
                    {colors.map((option) => (
                      <MenuItem key={option.value} value={option.value}>
                        {option.value}
                      </MenuItem>
                    ))}
                  </TextField>
                </Box>
                </CardContent>
                </Collapse>
                </Card>
              </Grid>
              <Grid
                item
                xs={12}
                sm={8}
                md={4}
              >
                <br></br>
                <Card>
                <CardHeader
                  title="Third Floor Details"
                  // subheader="sub"
                  titleTypographyProps={{ align: 'center' }}
                  // subheaderTypographyProps={{
                  //   align: 'center',
                  // }}
                  sx={{
                    backgroundColor: (theme) =>
                      theme.palette.mode === 'light'
                        ? theme.palette.grey[200]
                        : theme.palette.grey[700],
                  }}
                />
                 <CardActions>
                  <Grid container alignItems="center" justifyContent="center">
                     <IconButton onClick={() => setExpand3(!expand3)}>
                        <ArrowDropDown/>
                     </IconButton>
                  </Grid>
                </CardActions>
                <Collapse in={expand3}>
                <CardContent>
                <Box component="form" noValidate sx={{ mt: 1 }}>

                  <TextField
                    margin="normal"
                    fullWidth
                    name="thirdFloorHeadline"
                    label="Floor Headline"
                    type="thirdFloorHeadline"
                    id="thirdFloorHeadline"
                    onChange={handleThirdFloorHeadline}
                  />
                  <TextField
                    margin="normal"
                    fullWidth
                    name="thirdFloorClassDesc1"
                    label="Class Description"
                    type="thirdFloorClassDesc1"
                    id="thirdFloorClassDesc1"
                    onChange={handleThirdFloorClassDesc1}
                  />
                  <TextField
                    margin="normal"
                    //required
                    fullWidth
                    name="thirdFloorClassDesc2"
                    label="Class Description"
                    type="thirdFloorClassDesc2"
                    id="thirdFloorClassDesc2"
                    onChange={handleThirdFloorClassDesc2}
                  />
                  <TextField
                    margin="normal"
                    fullWidth
                    name="thirdFloorClassDesc3"
                    label="Class Description"
                    type="thirdFloorClassDesc3"
                    id="thirdFloorClassDesc3"
                    onChange={handleThirdFloorClassDesc3}
                  />
                  <TextField
                    margin="normal"
                    fullWidth
                    name="thirdFloorClassDesc4"
                    label="Class Description"
                    type="thirdFloorClassDesc4"
                    id="thirdFloorClassDesc4"
                    onChange={handleThirdFloorClassDesc4}
                  />
                  <TextField
                    margin="normal"
                    fullWidth
                    id="filled-select-color"
                    select
                    helperText="third floor background color"
                    variant="filled"
                    onChange={handleThirdFloorBackgroundColorChange}
                  >
                    {colors.map((option) => (
                      <MenuItem key={option.value} value={option.value}>
                        {option.value}
                      </MenuItem>
                    ))}
                  </TextField>
              </Box>
              </CardContent>
              </Collapse>
              </Card>
            </Grid>
          </Grid>
          <Button
              type="submit"
              fullWidth
              variant="contained"
              sx={{ mt: 3, mb: 2 }}
              onClick={handleSubmit}
              style = {{width: 300}}
            >
              Submit
          </Button>
    </Container>
    </ThemeProvider>
    )
};